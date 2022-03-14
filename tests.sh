 #!/bin/bash

 # cppcheck
 cppcheck --enable=all --suppress=missingInclude ./src/ ./inc/ ./testes/


 # lcov
 cd ./lcovdir
 lcov -c -d .. -o my.info
 genhtml -o results/ my.info 
 cd ..

