if [[ $(grep -c 'DOC*' $1) -gt 0 ]]; then
  echo "It's there!"
  chmod 777 $1
fi