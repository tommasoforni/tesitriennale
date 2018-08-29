#!/bin/bash
for i in $(ls ~/int/$1| grep out |grep -v png); do
	sed -i '/^;/ d' ~/int/$1/$i
done

echo "" > "plot/1_$1"
for i in $(ls $1 | grep 1_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    j=`./integrate $1/$i`
    echo $nome $j >> "plot/1_$1";
done

echo "" > "plot/2_$1"
for i in $(ls $1 | grep 2_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    j=`./integrate $1/$i`
    echo $nome $j >> "plot/2_$1";
done

echo "" > "plot/3_$1"
for i in $(ls $1 | grep 3_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    j=`./integrate $1/$i`
    echo $nome $j >> "plot/3_$1";
done

echo "" > "plot/4_$1"
for i in $(ls $1 | grep 4_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    j=`./integrate $1/$i`
    echo $nome $j >> "plot/4_$1";
done

echo "" > "plot/1_v_$1"
for i in $(ls $1 | grep 1_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    max=`./para $1/$i`
    echo $nome $max >> "plot/1_v_$1";
done

echo "" > "plot/2_v_$1"
for i in $(ls $1 | grep 2_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    max=`./para $1/$i`
    echo $nome $max >> "plot/2_v_$1";
done

echo "" > "plot/3_v_$1"
for i in $(ls $1 | grep 3_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    max=`./para $1/$i`
    echo $nome $max >> "plot/3_v_$1";
done

echo "" > "plot/4_v_$1"
for i in $(ls $1 | grep 4_ ); do
    nome="$i";
    nome=${nome::-4};
    nome=${nome##**_};
    max=`./para $1/$i`
    echo $nome $max >> "plot/4_v_$1";
done
