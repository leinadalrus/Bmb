<script setup lang="ts">
import { ref } from 'vue'
import { useStoreGallery } from '../(composables)/useStoreGallery'
import TradingCard from './TradingCard.vue'

const beywatches = ref<IBeyInfo[]>([])
</script>

<template>
    <section>
        <article>
            <div>
                <li v-for="bey in beywatches" :key="bey.id">
                    <TradingCard @vue:mounted="useStoreGallery()"></TradingCard>
                </li>
            </div>
        </article>
    </section>
</template>
