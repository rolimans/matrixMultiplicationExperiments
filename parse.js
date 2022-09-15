const fs = require('fs');

const src = process.argv[2];
const value = process.argv[3];

for (let i = 1; i <= 10; i++) {
  const content = fs
    .readFileSync(`results/${src}/${value}/${src}${i}.txt`, 'utf8')
    .split('\n')
    .slice(5, 11)
    .filter((v) => v !== '')
    .map((v) => v.trim().split(' ')[0])
    .join('\t');

  console.log(content);
}
