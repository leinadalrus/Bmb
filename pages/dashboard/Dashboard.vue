<script setup lang="ts">
import type { AlbumArtType } from '../(components)/AlbumArt.vue'
import AlbumArt from '../(components)/AlbumArt.vue'
import TradingCard, {
    type TradingCardType
} from '../(components)/TradingCard.vue'

interface IActivityView {
    id: number
    timeof: string
    logline: string
}

const activity = ref<IActivityView[]>([{ id: 0, timeof: '', logline: '' }])
const albums = ref<AlbumArtType[]>()
const cards = ref<TradingCardType[]>()
</script>

<template>
    <main>
        <section>
            <span v-for="i in cards" v-bind:key="i.id">
                <TradingCard
                    v-bind:title="i.title"
                    v-bind:author="i.author"
                    v-bind:content="i.content"
                    v-bind:flavour="i.flavour"
                    v-bind:group="i.group"
                    v-bind:image="i.image"
                    v-bind:tags="i.tags"
                />
            </span>
        </section>

        <section>
            <li v-for="i in albums" v-bind:key="i.id">
                <AlbumArt
                    v-bind:image="i.image"
                    v-bind:title="i.title"
                    v-bind:tags="i.tags"
                />
            </li>
        </section>

        <section>
            <li v-for="i in activity" v-bind:key="i.id">
                <i>{{ i.timeof }}</i>
                <p>{{ i.logline }}</p>
            </li>
        </section>
    </main>
</template>
