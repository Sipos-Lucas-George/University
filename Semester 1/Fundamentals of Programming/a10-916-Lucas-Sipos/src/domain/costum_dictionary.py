class CustomDictionaryIterator:
    def __init__(self, _, custom_dict):
        self.__custom_dict = list(custom_dict)
        self.__index = 0

    def __next__(self):
        if self.__index >= len(self.__custom_dict):
            raise StopIteration

        result = self.__custom_dict[self.__index]
        self.__index += 1
        return result


class CustomDictionary:
    def __init__(self):
        self.__data = {}

    def __len__(self):
        return len(self.__data)

    def __setitem__(self, key, value):
        self.__data[key] = value

    def __getitem__(self, item):
        return self.__data[item]

    def __delitem__(self, key):
        del self.__data[key]

    def __iter__(self):
        return CustomDictionaryIterator(self, self.__data)

    def getAll(self):
        return self.__data.values()
