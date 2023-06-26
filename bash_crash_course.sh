# echo "Hello World"

# name="CodeMite"

# read -p "Enter your name:> " name

# echo "Your name is = ${name}"

################################
# CONDITIONAL STATEMENTS
################################
# read -p "Enter your age:> " age

# if (( age > 18 )); then
#   echo "You are eligible to vote!"
# elif ((age == 18)); then
#   echo "You are 18!"
#   echo "You are eligible to vote!"
# else
#   echo "You are NOT eligible to vote!"
# fi

################################
# CASE (SWITCH) STATEMENTS
################################

# read -p "Enter you choice:> " choice

# case $choice in
#   1)
#     echo 'You entered 1'
#     ;;
#   'code')
#     echo "You entered 'code'"
#     ;;
#   *)
#     echo "This is default"
# esac

################################
# LOOPS
################################

# i=0
# while ((i < 10)); do
#   echo "Hello World ${i}"
#   ((i++))
# done

# i=0
# until ((i == 10)); do
#   echo "until Hello World ${i}"
#   ((i++))
# done

# imgs=$(ls ./imgs)
# cd imgs
# counter=1

# for each in $imgs; do
#   mv $each "$counter.png"
#   ((counter++))
# done

# function foo() {
#   local number_of_args=$#
#   local all_args=$*
#   echo "There are $number_of_args arguments passed"
#   echo "The values passed are '$all_args'"
# }

# foo 1 2 3 454

# function sum() {
#   # local first=$1
#   # local second=$2
#   # local result=$(($first + $second))
#   # echo $result

#   local result=0
#   for number in $@; do
#     result=$(($result + $number))
#   done

#   echo $result

# }

# result=$(sum 2 5 3 5 32)

# echo "The sum is = $result"

function heavy_printing() {
  if (($1 <= 10)); then
    local i=$1
    echo $i
    ((i++))
    heavy_printing $i
  fi
}

heavy_printing 0
