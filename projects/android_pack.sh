#!/bin/bash
proPath=`pwd`
APP_VERSION_CODE=$1
RESOURCE_VERSION_CODE=$2
sh $proPath/91_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/91_proj.android
sh $proPath/360_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/360_proj.android
sh $proPath/anzhi_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/anzhi_proj.android
sh $proPath/cmge_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/cmge_proj.android
sh $proPath/dangle_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/dangle_proj.android
sh $proPath/duoku_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/duoku_proj.android
sh $proPath/huawei_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/huawei_proj.android
sh $proPath/lenovo_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/lenovo_proj.android
sh $proPath/oppo_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/oppo_proj.android
sh $proPath/uc_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/uc_proj.android
sh $proPath/vivo_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/vivo_proj.android
sh $proPath/wandoujia_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/wandoujia_proj.android
sh $proPath/xiaomi_proj.android/pack.sh $APP_VERSION_CODE $RESOURCE_VERSION_CODE $proPath/xiaomi_proj.android