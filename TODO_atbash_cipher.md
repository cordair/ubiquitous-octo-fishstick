# Things to improve in the Atbash cipher program:


- Keep numbers the same: use a string with all the allowed characters (letters, numbers)
- Ignore non-alphanumerical characters like , . ! and so on: use -1 returned by find() to skip them in the for loop
- Ignore whitespaces: same

- The result of string.length() is a long unsigned int and apparently shouldn't be compared with just an int type

- Is it possible to specify which function you want to use after compiling the program? 
For example encode this, decode that...

- How to use command line arguments: specify the function you want (encode, decode) and message or file to encode / decode.

    Use an if branch for each possible command line argument: if encode -> call encode function ....
