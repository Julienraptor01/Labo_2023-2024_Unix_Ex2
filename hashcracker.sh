#!/bin/bash
if [ $# -eq 0 ]
then
	echo "Enter a hash between 0 and 96 :"
	read hash
else
	hash=$1
fi
if [ $hash -lt 0 ] || [ $hash -gt 96 ]
then
	echo "Invalid input"
	exit -1
fi
passwords=(a b c d e f g h i j k l m n o p q r s t u v w x y z bn ao bo ap bp aq bq ar br as bs at bt au bu av bv aw bw ax bx ay by az bz caq aar bar car aas bas cas aat bat cat aau bau cau aav bav cav aaw baw caw aax bax cax aay bay cay aaz baz caz daat aaau baau caau daau aaav baav caav daav aaaw baaw caaw daaw aaax baax caax daax aaay)
echo "The password is \"${passwords[$hash]}\""
