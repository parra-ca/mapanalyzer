#!/usr/bin/env bash
# cd directory of this script, and fix timestamp
cd -- "$(dirname "$0")"
timestamp=$(date +%Y%m%d_%H%M%S)

PW=12
PH=1.7
KSIZE=3
METRICS='AD'
BGMET='none'

echo -e "\033[1mEXPORT START: $0\033[0m"
for msize in 13 14 15 16 17 18 19 20; do
    make MAT_SIZE=$msize KER_SIZE=$KSIZE timestamp=$timestamp \
        MA_WIDTH=$PW MA_HEIGHT=$PH \
        MA_METRICS=$METRICS \
        MA_BGMET=$BGMET \
        MA_XORIENT='h' \
        build map plot
done
echo -e "\033[1mEXPORT END  : $0\033[0m"
