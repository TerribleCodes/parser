# Simulated Lexical Analyzer and Parser

- This program is designed to accept input strings such as `3+4*5` and evaluate the input string against the grammar productions and output the lexemes of the input 
string and corresponding token mapping.

```
E → TE´  
E´→ +TE´|Ɛ  
T → FT´  
T´→ *FT´|Ɛ  
F → (E)|id  
id → 0|1|2|3|4|5|6|7|8|9|a…z|A…Z  
```

## Prerequisites

- **Docker**: You need to have Docker installed on your system. You can download and install Docker from the [official Docker website](https://www.docker.com/get-started).

## Running the Program

1. **Clone the Repository**: Clone this repository to your local machine.
2. **Navigate to the Repository**: Open a terminal or Command Prompt and navigate to the directory containing the cloned repository.
3. **Build the Docker Image**:
   Run the following command to build the Docker image:
   
   ```
   docker build -t parser .
   ```

   This command builds a Docker image named "parser" based on the Dockerfile provided in the repository.

4. **Run the Docker Container**:

   Once the Docker image is built, run the following command to start a Docker container from the image:
   
   ```
   docker run -it parser
   ```

   This command starts a Docker container based on the "parser" image. The C program will execute automatically inside the container.

5. **Enter Input**:

   When the program prompts for input, you can provide it through the terminal where you ran the `docker run` command.

6. **View Output**:

   After providing input, the program will execute within the Docker container, and you'll see the output in your terminal.

## Additional Notes

- Ensure that the C file is saved with a `.c` extension.
- Make sure to provide valid input when prompted.
