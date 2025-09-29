#!/bin/bash

# CS-375 Assignment 2 Submission Script
# Creates a zip file with only the required source files

# Set submission info
STUDENT_NAME="Alex_Eskenazi"
ASSIGNMENT="CS375_Assignment2"
ZIP_NAME="${STUDENT_NAME}_${ASSIGNMENT}.zip"

echo "Creating submission zip: $ZIP_NAME"

# Remove old zip if it exists
rm -f "$ZIP_NAME"

# Create zip with only required files
zip "$ZIP_NAME" ./*.cpp ./*.h makefile

echo "Submission created: $ZIP_NAME"
echo ""
echo "Contents:"
unzip -l "$ZIP_NAME"