#!/bin/bash

input="   /bin/ls        ls               ls   "

# Girdi stringini boşluklara göre ayır ve diziye at
IFS=' ' read -ra words <<< "$input"

# Çıktıyı oluştur
output=""
for word in "${words[@]}"; do
    output+="/bin/$word "
done

# C programını çağır ve çıktıyı yazdır
./hsh <<< "$output"
