signulls: signulls.c
  gcc signulls.c -o signal
  
run: signulls
  ./signulls

clean:
  rm *~
  rm .out
