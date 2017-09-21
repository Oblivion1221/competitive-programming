def validate_pin(pin):
    return True if pin.isdigit() and (pin.__len__() == 4 or pin.__len__() == 6) else False
