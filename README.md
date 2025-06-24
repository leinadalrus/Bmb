# Bmb

## Bearing Mobius

# How to compile C17 programs with EMCC

```Sh
emcc websdl2Canvas.c -std=c17 -Os -s WASM=1 \
 -s USE_SDL=2 -s USE_WEBGL2=1 \
 -s FULL_ES2=1 \
 -s EXPORTED_RUNTIME_METHODS='["ccall","cwrap"]' \
 -o websdl2Canvas.js
```

# Nuxt Minimal Starter

Look at the [Nuxt documentation](https://nuxt.com/docs/getting-started/introduction) to learn more.

## Setup

Make sure to install dependencies:

```bash
# npm
npm install

# pnpm
pnpm install

# yarn
yarn install

# bun
bun install
```

## Development Server

Start the development server on `http://localhost:3000`:

```bash
# npm
npm run dev

# pnpm
pnpm dev

# yarn
yarn dev

# bun
bun run dev
```

## Production

Build the application for production:

```bash
# npm
npm run build

# pnpm
pnpm build

# yarn
yarn build

# bun
bun run build
```

Locally preview production build:

```bash
# npm
npm run preview

# pnpm
pnpm preview

# yarn
yarn preview

# bun
bun run preview
```

Check out the [deployment documentation](https://nuxt.com/docs/getting-started/deployment) for more information.
