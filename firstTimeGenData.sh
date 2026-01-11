#! /bin/zsh
###
 # @Author: LetMeFly
 # @Date: 2026-01-11 16:35:35
 # @LastEditors: LetMeFly.xyz
 # @LastEditTime: 2026-01-11 19:22:40
### 
cd Solutions
OUTPUT_FILE="../LastModifiedTime.json"
processed=0
bar_length=50
start_time=$(date +%s.%N)

format_elapsed_time() {
    local elapsed_seconds=$1
    local minutes=$(echo "$elapsed_seconds / 60" | bc)
    local seconds=$(echo "$elapsed_seconds % 60" | bc)
    if [ "$minutes" -eq 0 ]; then
        printf "%.1fs" "$seconds"
    else
        printf "%02dm%04.1fs" "$minutes" "$seconds"
    fi
}

echo "{" > "$OUTPUT_FILE"
total_files=$(find . -type f -name "*.md" | wc -l)
find . -type f -name "*.md" | while read -r file; do
    last_modified_time=$(git log -1 --format="%cI" -- "$file")
    [ -z "$last_modified_time" ] && last_modified_time=$(date -Iseconds)
    if [ $processed -gt 0 ]; then
        echo "," >> "$OUTPUT_FILE"
    fi
    echo -n "    \"${file#./}\": \"$last_modified_time\"" >> "$OUTPUT_FILE"
    
    ((processed++))
    percentage=$((processed * 100 / total_files))
    filled_length=$((processed * bar_length / total_files))
    bar=$(printf "%0.s#" $(seq 1 $filled_length))
    bar=$(printf "%-${bar_length}s" "$bar" | tr ' ' '-')
    current_time=$(date +%s.%N)
    elapsed_seconds=$(echo "$current_time - $start_time" | bc)
    elapsed_time=$(format_elapsed_time "$elapsed_seconds")
    printf "\r[%-${bar_length}s] %d%% (%d/%d) %s" "$bar" "$percentage" "$processed" "$total_files" "$elapsed_time"
done
echo "" >> "$OUTPUT_FILE"
echo -n "}" >> "$OUTPUT_FILE"

# [##################################################] 100% (1082/1082) 01m09.1s
