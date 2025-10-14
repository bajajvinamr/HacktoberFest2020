import re
from typing import Optional

def validate_and_format_phone(number: str, default_country_code: str = "+1") -> Optional[str]:
    """
    Validates and formats a phone number string into the E.164 international standard.
    
    E.164 format example: +CCNNNNNNNNNN (Country Code + Number, no spaces/dashes)
    
    Args:
        number (str): The raw input phone number string.
        default_country_code (str): The country code to prepend if one is missing (e.g., +1 for US/Canada).
        
    Returns:
        Optional[str]: The validated and formatted E.164 string, or None if invalid.
    """
    
    if not number:
        return None

    # 1. Remove all non-digit characters except for a leading '+'
    # We use regex to preserve the leading '+' if it exists.
    # The [^0-9] matches anything that is NOT a digit.
    cleaned_number = re.sub(r'[^\d\+]', '', number)
    
    # Remove any stray '+' signs that are not the first character
    if cleaned_number.count('+') > 1:
        # If multiple '+', it's likely malformed, but we clean it to try again
        cleaned_number = cleaned_number.replace('+', '')
    elif cleaned_number.count('+') == 1 and not cleaned_number.startswith('+'):
        # If '+' exists but not at the start, remove it
        cleaned_number = cleaned_number.replace('+', '')

    # 2. Basic Length Check (Standard E.164 numbers are usually 11-15 digits)
    # Strip any potential leading '+' for the length check
    digits_only = cleaned_number.lstrip('+')
    
    if not (7 <= len(digits_only) <= 15):
        # Log error or return None if the number of digits is unrealistic
        # print(f"Validation Error: Number of digits ({len(digits_only)}) is out of range.")
        return None

    # 3. Apply default country code if needed
    if not cleaned_number.startswith('+'):
        # Assume it's a local number missing the country code
        final_number = default_country_code + cleaned_number
    else:
        # Already has country code
        final_number = cleaned_number
        
    # 4. Final Sanity Check: Ensure it starts with a '+' and contains only digits afterwards
    if not final_number.startswith('+') or not final_number[1:].isdigit():
        # This shouldn't happen after step 1, but serves as a final safeguard.
        return None

    return final_number

# --- Demonstration ---
if __name__ == "__main__":
    test_numbers = [
        "123-456-7890",                  # US format, missing CC
        "(404) 555-1234",                # US format, missing CC
        "+44 20 7946 0958",              # UK international format
        "07700 900001",                  # UK local format (will assume default CC)
        "555-1212",                      # Too short (invalid)
        "++1-555-123-4567",              # Malformed (too many plus signs)
        "1(555) 123-4567 Ext. 200",      # Contains extra text/digits, missing CC
        ""                               # Empty string
    ]
    
    print("--- Phone Number Validation Utility ---")
    
    # Test with default CC (+1 for US/Canada)
    default_cc = "+1"
    print(f"\n--- Testing with Default Country Code: {default_cc} ---")
    for number in test_numbers:
        formatted = validate_and_format_phone(number, default_cc)
        status = "VALID" if formatted else "INVALID"
        print(f"Input: '{number:<25}' -> Output: '{formatted:<15}' Status: {status}")

    # Test with a different default CC (+91 for India)
    default_cc = "+91"
    print(f"\n--- Testing with Default Country Code: {default_cc} ---")
    for number in test_numbers:
        formatted = validate_and_format_phone(number, default_cc)
        status = "VALID" if formatted else "INVALID"
        print(f"Input: '{number:<25}' -> Output: '{formatted:<15}' Status: {status}")
