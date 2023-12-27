#!/bin/bash

# Önce mevcut ortam değişkenlerini yedekleyin
export ORTAM_DEGISKENLERI_YEDEGI=$(printenv)

# Sonra ortam değişkenlerini silebilirsiniz
for i in $(printenv | cut -d= -f1); do
    unset $i
done

# Test için öğrencinin kabuk programını burada çalıştırabilirsiniz
./hsh

# Test bittikten sonra ortam değişkenlerini geri yükleyin
export $(echo "$ORTAM_DEGISKENLERI_YEDEGI" | tr '\n' ' ')
