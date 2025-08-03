#!/bin/bash

PIPEX=./pipex
VALGRIND="valgrind --leak-check=full --track-fds=yes --trace-children=yes --child-silent-after-fork=no"

INFILE_OK=infiles/big_text.txt
INFILE_EMPTY=infiles/empty.txt
INFILE_NO=infiles/no_such_file.txt
OUTFILE=test_out.txt
OUTFILE_REF=test_ref.txt

mkdir -p infiles outfiles

# Prepare test files
echo -e "line1\nline2\nline3\nline4" > "$INFILE_OK"
> "$INFILE_EMPTY"

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

run_test() {
    local desc="$1"
    local infile="$2"
    local cmd1="$3"
    local cmd2="$4"
    local outfile="$5"

    echo -e "\n===== TEST: $desc ====="
    rm -f "$outfile" "$OUTFILE_REF"

    # Shell reference
    bash -c "< \"$infile\" $cmd1 | $cmd2 > \"$OUTFILE_REF\" 2>/dev/null"
    # Your pipex
    $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile" 2>/dev/null

    diff "$outfile" "$OUTFILE_REF" > /dev/null
    if [ $? -eq 0 ]; then
        echo -e "${GREEN}Output OK${NC}"
    else
        echo -e "${RED}Output Mismatch${NC}"
        echo "Expected:"
        cat "$OUTFILE_REF"
        echo "Got:"
        cat "$outfile"
    fi

    # Show exit codes
    bash -c "< \"$infile\" $cmd1 | $cmd2 > /dev/null"
    echo "Shell exit code: $?"
    $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile" > /dev/null
    echo "Pipex exit code: $?"

    # Valgrind check
    echo "--- Valgrind (leaks & fds) ---"
    $VALGRIND $PIPEX "$infile" "$cmd1" "$cmd2" "$outfile" > /dev/null 2>&1
}

### ---------- Mandatory Tests ----------

# 1. 正常ケース
run_test "Normal small file" "$INFILE_OK" "cat" "wc -l" "$OUTFILE"

# 2. 空ファイル
run_test "Empty infile" "$INFILE_EMPTY" "cat" "wc -l" "$OUTFILE"

# 3. infileが存在しない
run_test "Infile does not exist" "$INFILE_NO" "cat" "wc -l" "$OUTFILE"

# 4. 権限なしoutfile（作成できないケース）
touch outfiles/readonly.txt
chmod 000 outfiles/readonly.txt
run_test "Permission denied outfile" "$INFILE_OK" "cat" "wc -l" "outfiles/readonly.txt"
chmod 644 outfiles/readonly.txt

# 5. コマンドが存在しない
run_test "Invalid command1" "$INFILE_OK" "no_such_cmd" "wc -l" "$OUTFILE"
run_test "Invalid command2" "$INFILE_OK" "cat" "no_such_cmd" "$OUTFILE"

# 6. パイプ先が早期終了 (head -2)
run_test "Big file with head" "$INFILE_OK" "cat" "head -2" "$OUTFILE"

# 7. 空コマンド（permission denied互換）
run_test "Empty cmd2" "$INFILE_OK" "cat" "" "$OUTFILE"

# 8. 特殊文字・引数付き
run_test "Grep test" "$INFILE_OK" "cat -e" "grep line" "$OUTFILE"

echo -e "\n===== ALL TESTS DONE ====="

