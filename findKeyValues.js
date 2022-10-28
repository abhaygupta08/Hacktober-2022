    findKeyValues(valueKeyList = []) {
        let valueKeysToFind = {};
        let foundKeyList = {};
        valueKeyList.forEach(ele => {
            valueKeysToFind[ele] = true;
        })
        findKey(this.json, valueKeysToFind, foundKeyList);
        return foundKeyList
    }
