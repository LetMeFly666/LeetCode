#encoding: utf-8
'''
Author: LetMeFly
Date: 2023-03-16 21:24:02
LastEditors: LetMeFly
LastEditTime: 2023-03-16 21:56:34
'''
from bs4 import BeautifulSoup
import pandas as pd
import pyperclip

html_table = """
<table class="table table-sm">
<thead>
<tr>
<th>“设置”页面</th>
<th>URI</th>
</tr>
</thead>
<tbody>
<tr>
<td>修复令牌</td>
<td>ms-settings:workplace-repairtoken</td>
</tr>
</tbody>
</table>
"""

soup = BeautifulSoup(html_table, 'html.parser')

table = soup.find('table')
table_headers = [header.text for header in table.find_all('th')]

rows = []
for row in table.find_all('tr')[1:]:
    rows.append([val.text.replace('\n', '').replace('\xa0', '') for val in row.find_all('td')])

df = pd.DataFrame(rows, columns=table_headers)
markdown_table = df.to_markdown(index=False)

print(markdown_table)
pyperclip.copy(markdown_table)
