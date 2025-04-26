# Java Setup for Thread Examples

This directory contains Java examples related to thread creation and management.

## How to Install Java on Ubuntu

To compile and run Java programs, you need to have the Java Development Kit (JDK) installed. On Ubuntu, you can easily install OpenJDK using the following command:

```bash
sudo apt install openjdk-21-jdk
```

This command installs OpenJDK version 21, which includes both the Java Runtime Environment (JRE) and the Java compiler (`javac`).

### Verify Installation

After installation, you can verify that Java is correctly installed by running:

```bash
java -version
javac -version
```

Both commands should display version information for Java 21.

---

## How to Compile and Run `Driver.java`

1. **Navigate to the directory:**

   ```bash
   cd src/03-threads/java
   ```

2. **Compile the Java file:**

   ```bash
   javac Driver.java
   ```

   This will generate `Driver.class` and possibly `Summation.class`.

3. **Run the program:**

   ```bash
   java Driver 10
   ```

   Replace `10` with any integer to calculate the sum from 1 to that number.

---

Continue with the examples in this folder to learn about Java threads!
