path "./"
for i in {1..10000}
do
echo "run test on in-$i"
$2 $3 < $path/in-$i > $path/$1/out-$i
done