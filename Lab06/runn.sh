gcc -pthread main.c -o main
gcc main2.c -o main2
echo Paralela
time ./main 3
echo Serial
time ./main2