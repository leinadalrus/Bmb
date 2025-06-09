<script setup lang="ts">
defineProps({
    height: Number,
    width: Number,
    title: String,
    flavour: String,
    logline: String
})

type PosterType = {
    height: number
    width: number
    title: string
    flavour: string
    logline: string
}

type PosterMutationType = PosterType & {
    id: number
}
</script>

<template>
    <article
        id="poster-container"
        class="max-w-sm max-h-md rounded-b rounded-md shadow-lg text-[#0e020c] bg-[#f1eae4]"
    >
        <section class="px-2 py-1">
            <h1
                class="text-lg text-justify text-start font-light font-stretch-ultra-expanded italic"
            >
                {{ title }}
            </h1>
        </section>

        <section class="px-6 py-4">
            <i class="text-base italic">{{ flavour }}</i>
            <p class="font-medium text-md mb-2">{{ logline }}</p>
        </section>
    </article>
</template>

<style module="scoped" lang="scss"></style>
