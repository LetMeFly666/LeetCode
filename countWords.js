function countWords() {
    // 返回当前页面的单词总数 - 当前仅支持 https://blog.letmefly.xyz/2024/02/19/Other-English-LearningNotes-SomeWords/ 及其 arknights
    const tables = document.querySelectorAll('table');
    if (tables.length != 1) {
        return -1;
    }
    const table = tables[0];
    var ans = 0;
    const trs = table.querySelector('tbody').querySelectorAll('tr');
    for (var i = 0; i < trs.length; i++) {
        const word = trs[i].querySelector('td').innerText;
        if (word) {
            ans++;
        }
    }
    return ans;
}

function countWords_changeHTML() {
    const wordCount = countWords();
    const toChange = document.querySelectorAll('.wordCounts');
    for (var i = 0; i < toChange.length; i++) {
        toChange[i].innerHTML = `收录单词总数：${wordCount}`
    }
}

countWords_changeHTML();