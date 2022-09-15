SRCS=('matrixMultiplication' 'matrixMultiplicationInterchange' 'matrixMultiplicationUnrolling')
VALUES=(100 1000)

mkdir -p bin
mkdir -p results

for SRC in ${SRCS[@]}; do
  echo "Compiling $SRC"
  gcc -o ./bin/$SRC ./src/$SRC.c
done

echo "Running experiments"

for SRC in ${SRCS[@]}; do
  for VALUE in ${VALUES[@]}; do
    mkdir -p results/$SRC/$VALUE
    for i in {1..10}; do
      echo "Running $SRC with $VALUE for the $i time"
      perf stat -o ./results/$SRC/$VALUE/$SRC$i.txt -e L1-dcache-load,L1-dcache-load-misses,branch-instructions,branch-misses ./bin/$SRC $VALUE
    done
  done
done
