CS 202 - Programming Assignment 2

This repository contains my implementation of Binary Search Trees (BST) and various tree traversal algorithms in C++. The assignment focuses on implementing key BST operations, tree traversals, and an applicant shortlisting system using different traversal strategies.

📌 Features & Concepts Covered

1️. Binary Search Tree (BST) Implementation
The BST stores applicant details: name, experience, and gender, while maintaining left and right pointers. It supports essential operations such as inserting a new applicant, deleting an applicant by experience key, searching for an applicant, and calculating tree height. The implementation utilizes smart pointers (shared_ptr) for efficient memory management.

2. Tree Traversal Algorithms
Different traversal methods are implemented to shortlist job applicants based on experience. The default selection algorithm follows the right-most path traversal, but alternatives include in-order, pre-order, post-order, and level-order traversals.

3️. Algorithmic Resume Shortlisting
The BST orders applicants based on years of experience, and different traversal techniques help prioritize candidates for interviews. The number of shortlisted applicants is determined based on traversal depth.

📂 Folder & File Structure

The project consists of key files necessary for BST operations and traversal implementation:

bst.hpp - Defines BST structure and function prototypes.
bst.cpp - Implements BST operations.
traversal.cpp - Implements traversal strategies.

(tests were included in the initial assignment to check correct implementation of the BST, but since that is not my own work, I have not included them here.)

🔗 Technologies & Concepts Used

This project is implemented in C++, utilizing smart pointers (shared_ptr), Binary Search Tree (BST) operations, tree traversal algorithms, and algorithmic design for job applicant shortlisting.

📜 Acknowledgments

This assignment is part of LUMS CS 202 - Data Structures coursework, Fall 2023. Note: My code follows academic integrity guidelines and the implementation is strictly my own work.

