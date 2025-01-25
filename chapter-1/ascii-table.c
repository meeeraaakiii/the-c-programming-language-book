#include <stdio.h>
#include <ctype.h>

// Function to print binary representation of a number
void printBinary(int n) {
    for (int i = 7; i >= 0; i--) { // 8-bit binary representation
        putchar((n & (1 << i)) ? '1' : '0');
    }
}

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

int main() {
    printf("ASCII Table\n");
    printf("Char      | Dec  | Hex  | Oct   | Binary\n");
    printf("----------+------+------+-------+----------------\n");

    for (int i = 0; i <= 127; i++) {
        const char* specialCharName = getSpecialCharName(i);

        // Determine the character display: special name, printable char, or blank
        if (specialCharName) {
            printf("%-10s| %3d  | 0x%02X | %03o   | ", specialCharName, i, i, i);
        } else if (isprint(i)) {
            printf("'%c'       | %3d  | 0x%02X | %03o   | ", i, i, i, i);
        } else {
            printf("Non-print | %3d  | 0x%02X | %03o   | ", i, i, i);
        }

        // Print binary representation
        printBinary(i);
        printf("\n");
    }

    return 0;
}
