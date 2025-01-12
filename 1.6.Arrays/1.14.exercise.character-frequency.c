// Print a histogram of lengths of words in the input. Words up to 20 characters until we learn dynamic memory.

#include <stdio.h>
#include <ctype.h>

#define MAX_CHAR_NUMBER 127 // Only regular ASCII characters, no extended character set

// Function to handle special character names
const char* getSpecialCharName(int ch) {
    switch (ch) {
        case 0: return "NUL";  // Null
        case 1: return "SOH";  // Start of Heading
        case 2: return "STX";  // Start of Text
        case 3: return "ETX";  // End of Text
        case 4: return "EOT";  // End of Transmission
        case 5: return "ENQ";  // Enquiry
        case 6: return "ACK";  // Acknowledge
        case 7: return "BEL";  // Bell (\a)
        case 8: return "BS";   // Backspace (\b)
        case 9: return "HT";   // Horizontal Tab (\t)
        case 10: return "LF";  // Line Feed (\n)
        case 11: return "VT";  // Vertical Tab (\v)
        case 12: return "FF";  // Form Feed (\f)
        case 13: return "CR";  // Carriage Return (\r)
        case 14: return "SO";  // Shift Out
        case 15: return "SI";  // Shift In
        case 16: return "DLE"; // Data Link Escape
        case 17: return "DC1"; // Device Control 1
        case 18: return "DC2"; // Device Control 2
        case 19: return "DC3"; // Device Control 3
        case 20: return "DC4"; // Device Control 4
        case 21: return "NAK"; // Negative Acknowledge
        case 22: return "SYN"; // Synchronous Idle
        case 23: return "ETB"; // End of Transmission Block
        case 24: return "CAN"; // Cancel
        case 25: return "EM";  // End of Medium
        case 26: return "SUB"; // Substitute
        case 27: return "ESC"; // Escape (\e in some compilers)
        case 28: return "FS";  // File Separator
        case 29: return "GS";  // Group Separator
        case 30: return "RS";  // Record Separator
        case 31: return "US";  // Unit Separator
        case 32: return "SP";  // Space (' ')
        case 127: return "DEL"; // Delete
        default: return NULL;  // No special name
    }
}

void main() {
    int character, length = 0;
    int charsLengths[MAX_CHAR_NUMBER]; // Array to count word lengths
    for (int i = 0; i <= MAX_CHAR_NUMBER; ++i) {
        charsLengths[i] = 0;
    }

    while ((character = getchar()) != EOF) {
        if (character > 127) {
            // skip it if it's not in regular ASCII charset
            continue;
        }
        charsLengths[character]++;
    }

    for (int i = 0; i < MAX_CHAR_NUMBER; i++) {
        const char* specialCharName = getSpecialCharName(i);

        // Determine the character display: special name, printable char, or blank
        if (specialCharName) {
            printf("%-3s: ", specialCharName);
        } else if (isprint(i)) {
            printf("'%c': ", i);
        }
        int lengthOfTheCurrentChar = charsLengths[i];
        for (int barCounter = 0; barCounter < lengthOfTheCurrentChar; barCounter++) {
            putchar('|');
        }
        putchar('\n');
    }
}
