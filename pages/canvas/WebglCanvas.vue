<script setup lang="ts">
import { onMounted, ref } from 'vue'
const webglCanvas = ref(undefined)

onMounted(async () => {
    const component = await import(
        /* @vite-ignore */ '~/server/api/webgl/websdl2Canvas'
    )

    component.default({
        Canvas: webglCanvas.value
    })
})
</script>

<template>
    <canvas
        id="gl-canvas-container"
        ref="webglCanvas"
        width="540"
        height="432"
    ></canvas>
</template>
