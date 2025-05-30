<script setup lang="ts">
import WindowTabs from './(components)/WindowTabs.vue'
import AsideBar from './(components)/AsideBar.vue'
</script>

<template>
    <div
        class="flex h-screen items-center justify-center text-[#f1eae4] bg-[#130b06]"
    >
        <main class="flex flex-col items-center">
            <section class="content">
                <article class="container-fluid">
                    <WindowTabs />
                </article>
            </section>
        </main>

        <AsideBar />
    </div>
</template>
