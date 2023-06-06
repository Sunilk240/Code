class Set:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def contains(self, element):
        return element in self.elements

    def size(self):
        return len(self.elements)

    def iterator(self):
        return iter(self.elements)

    def intersection(self, other_set):
        result_set = Set()
        for element in self.elements:
            if other_set.contains(element):
                result_set.add(element)
        return result_set

    def union(self, other_set):
        result_set = Set()
        result_set.elements = self.elements.copy()
        for element in other_set.elements:
            result_set.add(element)
        return result_set

    def difference(self, other_set):
        result_set = Set()
        for element in self.elements:
            if not other_set.contains(element):
                result_set.add(element)
        return result_set

    def is_subset(self, other_set):
        for element in self.elements:
            if not other_set.contains(element):
                return False
        return True

set1 = Set()
set1.add(1)
set1.add(2)
set1.add(3)

set2 = Set()
set2.add(2)
set2.add(3)
set2.add(4)

print("Set 1:", set1.elements)
print("Set 2:", set2.elements)

print("Intersection:", set1.intersection(set2).elements)
print("Union:", set1.union(set2).elements)
print("Difference (set1 - set2):", set1.difference(set2).elements)
print("Difference (set2 - set1):", set2.difference(set1).elements)

print("Is Set 1 a subset of Set 2?", set1.is_subset(set2))


print(set1.iterator())