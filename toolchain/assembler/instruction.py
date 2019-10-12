class Instruction:
    def __init__(self, operation, operand1, operand2):
        self.operation = operation
        self.operand1 = operand1
        self.operand2 = operand2
    def __str__(self):
        return "{} {},{}".format(self.operation, self.operand1, self.operand2)
