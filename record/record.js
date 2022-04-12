// node --max-old-space-size=8192
const records = [];

// FAIL: 112813859
for (let i = 0; i < 112813858; i++) {
  const record = {};

  record.id = i;
  records[i] = record;
}
