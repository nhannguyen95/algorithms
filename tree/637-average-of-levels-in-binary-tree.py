# Solution 1: same as solution 1 of C++ file
# note: use python3
def averageOfLevels(self, root):
    averages = []
    level = [root]
    while level:
        averages.append(sum(node.val for node in level) / len(level))
        level = [kid for node in level for kid in (node.left, node.right) if kid]
    return averages
