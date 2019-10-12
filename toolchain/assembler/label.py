class Label:
    def __init__(self, label_name):
        self.label_name = label_name
    def __str__(self):
        return "{}:".format(self.label_name)
