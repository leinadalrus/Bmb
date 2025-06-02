<script setup lang="ts">
import TradingCard from './TradingCard.vue'

const tags = ref<String[]>([''])

const isModalActive = ref(false)
const setModalAsActive = ref(false)

function handleMouseOver() {
    setModalAsActive.value = true
}

function handleMouseOut() {
    setModalAsActive.value = false
}

function handleFocus() {
    setModalAsActive.value = true
}

function handleFocusLoss() {
    setModalAsActive.value = false
}
</script>
<template>
    <div
        v-on:focus="handleFocus()"
        v-on:blur="handleFocusLoss()"
        v-on:mouseover="handleMouseOver()"
        v-on:mouseout="handleMouseOut()"
    >
        <TradingCard
            title="title"
            content="content"
            flavour="flavour"
            image="image"
            author=""
            group=""
            v-bind:tags="tags"
        />
    </div>
</template>
