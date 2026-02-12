import RaylibModuleFactory from "./quick_example.js";

function loop(instance, numiro) {
  numiro++;
  setTimeout(() => {
    loop(instance, numiro);
  }, 250);
}

export async function initGame() {
  const instance = await RaylibModuleFactory({
    canvas: document.getElementById("canvas"),
    // Opcional: capturar prints do C (printf) no console do JS
    print: (text) => console.log(`[Raylib]: ${text}`),
  });

  let numiro = 0;
  instance.setNumiro(numiro);
  return instance;
}

initGame();
