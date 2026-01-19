#!/usr/bin/env bash
# cd directory of this script, and fix timestamp
cd -- "$(dirname "$0")"
timestamp=$(date +%Y%m%d_%H%M%S)

CACHE=cache512.conf
MAT_SIZE=80
PW=4.2
PH=7.2
PLOTS='CMMA'
XRANGES='full'
YRANGES='CMMA:0:3200'
TBOXOFF='CMMA:0.01:0.98'
MRES=420

echo -e "\033[1mEXPORT START: $0\033[0m"
for min_size in 80 40 20 10 05 01; do
    make MAT_SIZE=$MAT_SIZE MIN_SIZE=$min_size timestamp=$timestamp \
        MA_CACHE=$CACHE \
        MA_WIDTH=$PW MA_HEIGHT=$PH \
        MA_METRICS=$PLOTS \
        MA_XRANGES=$XRANGES \
        MA_YRANGES=$YRANGES \
        MA_MAXRES=$MRES \
        MA_TBOXOFF=$TBOXOFF \
        build map plot
done
echo -e "\033[1mEXPORT END  : $0\033[0m"
