class MinStack:
    stack = []
    minimums = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.stack.append(x)

        if len(self.minimums) == 0 or self.minimums[-1] >= x:
            self.minimums.append(x)

    # @return nothing
    def pop(self):
        if len(self.stack) == 0:
            return

        top = self.stack[-1]
        self.stack.pop()

        if top == self.minimums[-1]:
            self.minimums.pop()

    # @return an integer
    def top(self):
        if len(self.stack) != 0:
            return self.stack[-1]
        return -1

    # @return an integer
    def getMin(self):
        if len(self.minimums) != 0:
            return self.minimums[-1]
        return -1

    def __init__(self):
        self.stack = []
        self.minimums = []
