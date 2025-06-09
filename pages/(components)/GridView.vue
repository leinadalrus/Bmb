<script setup lang="ts">
import AlbumArt, { type AlbumArtType } from './AlbumArt.vue'

const albums = ref<AlbumArtType[]>()
</script>

<template>
    <section
        class="grid grid-cols-3 grid-rows-[repeat(auto-fit,_minmax(12.5rem,_1fr))] gap-4"
        v-for="i in albums"
    >
        <AlbumArt :title="i?.title" :image="i?.image" v-bind:tags="i.tags" />
    </section>
</template>
