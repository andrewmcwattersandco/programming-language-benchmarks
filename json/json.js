(async () => {
  const { readdir, readFile } = require('fs/promises');

  const path = 'companyfacts';

  try {
    const files = await readdir(path);
    for (const file of files) {
      if (!file.endsWith('.json'))
        continue;

      const json = await readFile(path + '/' + file);
      JSON.parse(json);
    }
  } catch (err) {
    console.error(err);
  }
})();
