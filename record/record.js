// node --max-old-space-size=8192
const records = [];

// FAIL:  67108865
for (let i = 0; i < 33554432; i++) {
  const record = {};

  record.id = i;
  records[i] = record;
}
