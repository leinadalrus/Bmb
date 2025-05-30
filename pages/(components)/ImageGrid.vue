<script setup lang="ts">
import { ref } from 'vue'
import { useStoreGallery } from '../(composables)/useStoreGallery'
import TradingCard from './TradingCard.vue'
import type { IProductInfo } from '~/src/models/IProductInfo'

const gearwatchers = ref<IProductInfo[]>([])
</script>

<template>
    <section>
        <article>
            <div>
                <li v-for="gear in gearwatchers" :key="gear.id">
                    <TradingCard @vue:mounted="useStoreGallery()"></TradingCard>
                </li>
            </div>
        </article>
    </section>
</template>
