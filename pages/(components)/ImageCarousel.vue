<script setup lang="ts">
import { computed, ref } from 'vue'

type ImageCarouselType = {
    src: string
    srcset: string
    alt: string
    width: number
    height: number
}

export type ImageCarouselMutationType = ImageCarouselType & {
    id: number
}

const images = ref<ImageCarouselMutationType[]>([])
const currentIdx = ref(0)

const prevImage = computed(() => {
    let retValue = 0
    if (currentIdx.value > 0) retValue = currentIdx.value - 1

    return retValue
})

const nextImage = computed(() => {
    let retValue = 0
    if (currentIdx.value < 0) retValue = currentIdx.value + 1

    return retValue
})
</script>

<template>
    <span>
        <button :click="prevImage" :disabled="currentIdx == 0">
            &leftarrowtail; Previous
        </button>
        <img
            :src="images[currentIdx].src"
            :alt="images[currentIdx].alt"
            :srcset="images[currentIdx].srcset"
            :width="images[currentIdx].width"
            :height="images[currentIdx].height"
        />
        <button :click="nextImage" :disabled="currentIdx == images.length - 1">
            Next &rightarrowtail;
        </button>
    </span>
</template>
