# C++ Projects
A series of projects as I try to learn the ins and outs of the C++ language.

# Background
This is my attempt to get a handle on coding in the C++ language. It's based on a Quora post and answer found <a href="https://www.quora.com/What-are-some-of-the-best-C-C++-projects-beginners-can-try">here</a>.

In case you can't follow the link or the answer has been removed, the answer I was reading recommended a series of projects in this order:

# Easy

- Binary to Decimal and Back Converter - Develop a converter to convert a decimal number to binary or a binary number to its decimal equivalent.

- Unit Converter (temp, currency, volume, mass and more) - Converts various units between one another. The user enters the type of unit being entered, the type of unit they want to convert to and then the value. The program will then make the conversion.

- Count Vowels - Enter a string and the program counts the number of vowels in the text. For added complexity have it report a sum of each vowel found.

- Check if Palindrome - Checks if the string entered by the user is a palindrome. That is that it reads the same forwards as backwards like “racecar”

- Count Words in a String - Counts the number of individual words in a string. For added complexity read these strings in from a text file and generate a summary.


# Medium

- Page Scraper - Create an application which connects to a site and pulls out all links, or images, and saves them to a list. Optional: Organize the indexed content and don’t allow duplicates. Have it put the results into an easily searchable index file.

- Caesar cipher - Implement a Caesar cipher, both encoding and decoding. The key is an integer from 1 to 25. This cipher rotates the letters of the alphabet (A to Z). The encoding replaces each letter with the 1st to 25th next letter in the alphabet (wrapping Z to A). So key 2 encrypts "HI" to "JK", but key 20 encrypts "HI" to "BC". This simple "monoalphabetic substitution cipher" provides almost no security, because an attacker who has the encoded message can either use frequency analysis to guess the key, or just try all 25 keys.

- PDF Generator - An application which can read in a text file, html file or some other file and generates a PDF file out of it. Great for a web based service where the user uploads the file and the program returns a PDF of the file. Optional: Deploy on GAE or Heroku if possible.


# Hard
- Credit Card Validator - Takes in a credit card number from a common credit card vendor (Visa, MasterCard, American Express, Discoverer) and validates it to make sure that it is a valid number (look into how credit cards use a checksum).

- Dijkstra’s Algorithm - Create a program that finds the shortest path through a graph using its edges.

- Text Editor - Notepad style application that can open, edit, and save text documents. Optional: Add syntax highlighting and other features.

# Tools Used
I have been primarily coding in Visual Studio Community 2019.

For GUI projects, I use QT 5.12.6 (MSVC 2017 64-bit)

For work with PDF files, I have been using the libHaru library.
