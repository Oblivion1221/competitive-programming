def alphabet_position(text):
    return " ".join([str(ord(c.lower()) - 96) for c in text if c.isalpha()])