// node --max-old-space-size=8192
const records = [];

// FAIL:  67108865
for (let i = 0; i < 67108864; i++) {
  const record = {};

  record.id = i;
  records[i] = record;
}
