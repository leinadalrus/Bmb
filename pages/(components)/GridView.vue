<script setup lang="ts">
import AlbumArt from './AlbumArt.vue'

const tags = ref<String[]>([''])
</script>

<template>
    <section
        class="grid grid-cols-3 grid-rows-[repeat(auto-fit,_minmax(12.5rem,_1fr))] gap-4"
    >
        <AlbumArt title="Hello World!" image="" v-bind:tags="tags" />
    </section>
</template>
