<script setup lang="ts">
import TradingCard from './TradingCard.vue'

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
            tags=""
        />
    </div>
</template>
