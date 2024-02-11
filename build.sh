#!/bin/bash
start=$(date +%s)

if [ -d "./out" ]; then
  rm -r ./out
fi
mkdir ./out

echo Compiling kernel sources...

compiled=""
for file in ./kernel/** ./kernel/**/* ./kernel/**/**/*
do
  filename=$(basename -- "$file")
  
  if [[ "$file" == *.c ]]; then
    echo "$filename"
    gcc -O3 -I./kernel -ffreestanding -m32 -fno-pie -c $file -o out/${filename%.*}.elf
    compiled="${compiled} out/${filename%.*}.elf"
  fi
done

nasm boot/kernel_entry.asm -f elf32 -o out/kernel_entry.elf
nasm kernel/interrupt.asm -f elf32 -o out/interrupt.elf

nasm -f bin boot/boot.asm -o out/boot.bin

ld --allow-multiple-definition -m elf_i386 -o out/kernel.bin -Ttext 0x1000 out/kernel_entry.elf out/interrupt.elf ${compiled} --oformat binary

cat out/boot.bin out/kernel.bin > out/ravenos-i386.img

truncate -s 1474560 ./out/ravenos-i386.img

end=$(date +%s)
elapsed=$(($end-$start))

echo "Build completed successfully in $elapsed seconds"