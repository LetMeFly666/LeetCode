#!/bin/bash
set -e

HEIC="IMG_51901.HEIC.heic"
MOV="IMG_5190.HEIC.mov"
from=106
to=225

OUTDIR="../exported"
mkdir -p "$OUTDIR"

# 获取文件大小（macOS / Linux 通用）
filesize() {
    stat -f%z "$1" 2>/dev/null || stat -c%s "$1"
}

HEIC_SIZE=$(filesize "$HEIC")
MOV_SIZE=$(filesize "$MOV")

# 转8位大写16进制
hex8() {
    printf "%08X" "$1"
}

PART3=$(hex8 "$HEIC_SIZE")
PART6=$(hex8 "$MOV_SIZE")

echo "HEIC size: $HEIC_SIZE ($PART3)"
echo "MOV  size: $MOV_SIZE ($PART6)"

for offset in $(seq $from $to); do
    PART5=$(hex8 $((HEIC_SIZE + offset)))

    COMMENT="000200000030${PART3}0003${PART5}${PART6}313030304C495650"

    OUTFILE=$(printf "%s/%03d.livp" "$OUTDIR" "$offset")

    zip -q -0 -X -z "$OUTFILE" "$HEIC" "$MOV" <<EOF
$COMMENT
EOF

    echo "Generated $(basename "$OUTFILE")  part5=$PART5"
done

echo "Done."